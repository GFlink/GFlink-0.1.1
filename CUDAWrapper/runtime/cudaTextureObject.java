

package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a cudaTextureObject
 */
public class cudaTextureObject extends NativePointerObject
{
    /**
     * Creates a new, uninitialized cudaTextureObject
     */
    public cudaTextureObject()
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
        return "cudaTextureObject["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }
}
