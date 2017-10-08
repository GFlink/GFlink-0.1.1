package CUDAWrapper.runtime;

/**
 * Java port of the cudaChannelFormatDesc.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.
 *
 * @see CUDAWrapper#cudaMallocArray
 * @see CUDAWrapper#cudaMalloc3DArray
 * @see cudaChannelFormatKind
 */
public class cudaChannelFormatDesc
{
    /**
     * Number of bits in x component
     */
    public int x;

    /**
     * Number of bits in y component
     */
    public int y;

    /**
     * Number of bits in z component
     */
    public int z;

    /**
     * Number of bits in w component
     */
    public int w;

    /**
     * The channel format kind. Must be one of the cudaChannelFormatKind values.
     *
     * @see cudaChannelFormatKind
     */
    public int f;

    /**
     * Creates an uninitialized cudaChannelFormatDesc
     */
    public cudaChannelFormatDesc()
    {
    }

    /**
     * Creates a cudaChannelFormatDesc with the given bit counts
     * and the given format kind.
     *
     * @param x Number of bits in x component
     * @param y Number of bits in y component
     * @param z Number of bits in z component
     * @param w Number of bits in w component
     * @param f The format kind
     *
     * @see cudaChannelFormatKind
     */
    public cudaChannelFormatDesc(int x, int y, int z, int w, int f)
    {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
        this.f = f;
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "cudaChannelFormatDesc["+
            "x="+x+","+
            "y="+y+","+
            "z="+z+","+
            "w="+w+","+
            "f="+cudaChannelFormatKind.stringFor(f)+"]";
    }

}
