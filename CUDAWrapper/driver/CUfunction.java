
package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUfunction.
 *
 * @see CUDAWrapperDriver#cuModuleGetFunction
 * @see CUDAWrapperDriver#cuModuleLoad
 * @see CUDAWrapperDriver#cuModuleLoadData
 * @see CUDAWrapperDriver#cuModuleLoadFatBinary
 * @see CUDAWrapperDriver#cuModuleUnload
 * @see CUDAWrapperDriver#cuModuleGetGlobal
 * @see CUDAWrapperDriver#cuModuleGetTexRef
 */
public class CUfunction extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUfunction
     */
    public CUfunction()
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
        return "CUfunction["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
