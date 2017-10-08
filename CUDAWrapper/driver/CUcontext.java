

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUcontext.
 *
 * @see CUDAWrapperDriver#cuCtxCreate
 * @see CUDAWrapperDriver#cuCtxAttach
 * @see CUDAWrapperDriver#cuCtxDetach
 * @see CUDAWrapperDriver#cuCtxDestroy
 * @see CUDAWrapperDriver#cuCtxPushCurrent
 * @see CUDAWrapperDriver#cuCtxPopCurrent
 */
public class CUcontext extends NativePointerObject
{

    /**
     * Creates a new, uninitialized CUcontext
     */
    public CUcontext()
    {
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "CUcontext["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
