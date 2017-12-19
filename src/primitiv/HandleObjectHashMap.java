/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

import java.lang.ref.Reference;
import java.lang.ref.WeakReference;
import java.lang.ref.ReferenceQueue;
import java.util.HashMap;


class HandleObjectHashMap<T> extends HashMap<Long, HandleObjectHashMap<T>.WeakRefObject> {
    private ReferenceQueue<T> q_ = new ReferenceQueue<T>();

    public class WeakRefObject extends WeakReference<T> {
        private Long handle_;

        public WeakRefObject(Long handle, T obj, ReferenceQueue<T> q) {
            super(obj, q);
            handle_ = handle;
        }

        public Long getHandle() {
            return handle_;
        }
    }

    private void cleanQueue() {
        Reference<?> ref;
        while ((ref = q_.poll()) != null) {
            @SuppressWarnings("unchecked")
            WeakRefObject refobj = (WeakRefObject) ref;
            super.remove(refobj.getHandle());
        }
    }

    private final T getWrapped(WeakRefObject obj) {
        if (obj == null) {
            return null;
        } else {
            return obj.get();
        }
    }

    public T get(Long handle) {
        return getWrapped(super.get(handle));
    }

    public T put(Long handle, T obj) {
        cleanQueue();
        return getWrapped(super.put(handle, new WeakRefObject(handle, obj, q_)));
    }

    public boolean containsKey(Long handle) {
        cleanQueue();
        return super.containsKey(handle);
    }
}
