

package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a cudaSurfaceObject
 */
public class cudaSurfaceObject extends NativePointerObject
{
    /**
     * Creates a new, uninitialized cudaSurfaceObject
     */
    public cudaSurfaceObject()
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
        return "cudaSurfaceObject["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }
}
