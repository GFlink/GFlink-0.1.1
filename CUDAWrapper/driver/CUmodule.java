

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUmodule.
 *
 * @see CUDAWrapperDriver#cuModuleLoadData
 * @see CUDAWrapperDriver#cuModuleLoadFatBinary
 * @see CUDAWrapperDriver#cuModuleUnload
 * @see CUDAWrapperDriver#cuModuleGetFunction
 * @see CUDAWrapperDriver#cuModuleGetGlobal
 * @see CUDAWrapperDriver#cuModuleGetTexRef
 */
public class CUmodule extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUmodule
     */
    public CUmodule()
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
        return "CUmodule["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
