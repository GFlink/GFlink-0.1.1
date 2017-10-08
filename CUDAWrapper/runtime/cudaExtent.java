package CUDAWrapper.runtime;

/**
 * Java port of a cudaExtent.
 *
 * @see CUDAWrapper#cudaMalloc3D
 * @see CUDAWrapper#cudaMemset3D
 * @see CUDAWrapper#cudaMalloc3DArray
 *
 */
public class cudaExtent
{
    /**
     * The width of this cudaExtent, in elements
     */
    public long width;

    /**
     * The height of this cudaExtent, in elements
     */
    public long height;

    /**
     * The depth of this cudaExtent
     */
    public long depth;

    /**
     * Creates a new cudaExtent with all-zero sizes
     */
    public cudaExtent()
    {
    }

    /**
     * Creates a new cudaExtent with the given sizes
     *
     * @param width The width of the cudaExtent
     * @param height The height of the cudaExtent
     * @param depth The depth of the cudaExtent
     */
    public cudaExtent(int width, int height, int depth)
    {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    /**
     * Creates a new cudaExtent with the given sizes
     *
     * @param width The width of the cudaExtent
     * @param height The height of the cudaExtent
     * @param depth The depth of the cudaExtent
     */
    public cudaExtent(long width, long height, long depth)
    {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "cudaExtent["+
            "width="+width+","+
            "height="+height+","+
            "depth="+depth+"]";
    }

}