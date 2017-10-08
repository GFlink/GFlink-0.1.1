package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a surfaceReference.<br />
 */
public class surfaceReference extends NativePointerObject
{
    /**
     * Describes the format of the value that is returned when fetching
     * the surface.
     *
     * @see cudaChannelFormatDesc
     */
    private cudaChannelFormatDesc channelDesc;

    /**
     * Creates a new, uninitialized textureReference
     */
    public surfaceReference()
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
        return "surfaceReference[" +
                "nativePointer=0x"+Long.toHexString(getNativePointer())+","+
                "channelDesc="+channelDesc+"]";


    }
}
