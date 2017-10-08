package CUDAWrapper.nvrtc;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a nvrtcProgram
 */
public class nvrtcProgram extends NativePointerObject
{
    /**
     * Creates a new, uninitialized nvrtcProgram
     */
    public nvrtcProgram()
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
        return "nvrtcProgram["+
            "nativePointer="+getNativePointer()+"]";
    }

}
