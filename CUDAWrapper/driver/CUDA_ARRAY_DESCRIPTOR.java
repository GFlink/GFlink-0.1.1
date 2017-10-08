

package CUDAWrapper.driver;

/**
 * Java port of a CUDA_ARRAY_DESCRIPTOR.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.
 *
 * @see CUDAWrapperDriver#cuArrayCreate
 * @see CUDAWrapperDriver#cuArrayGetDescriptor
 */
public class CUDA_ARRAY_DESCRIPTOR
{
    /**
     * Width is the width of the CUDA array (in elements);
     */
    public long Width;

    /**
     * Height is the height of the CUDA array (in elements); the CUDA array is
     * one-dimensional if height is 0, two-dimensional, otherwise;
     */
    public long Height;

    /**
     * Format specifies the format of the elements;
     *
     * @see CUarray_format
     */
    public int Format;

    /**
     * NumChannels specifies the number of packed components per CUDA array element.; it may be 1, 2 or 4
     */
    public int NumChannels;

    /**
     * Creates a new, uninitialized CUDA_ARRAY_DESCRIPTOR
     */
    public CUDA_ARRAY_DESCRIPTOR()
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
        return "CUDA_ARRAY3D_DESCRIPTOR["+
            "Width="+Width+","+
            "Height="+Height+","+
            "CUarray_format_Format="+Format+","+
            "NumChannels="+NumChannels+"]";
    }

}
