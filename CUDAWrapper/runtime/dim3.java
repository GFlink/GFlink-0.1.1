package CUDAWrapper.runtime;

/**
 * Java port of a dim3.
 *
 * @see CUDAWrapper#cudaConfigureCall
 */
public class dim3
{
    /**
     * The x size
     */
    public int x = 1;

    /**
     * The y size
     */
    public int y = 1;

    /**
     * The z size
     */
    public int z = 1;

    /**
     * Creates a new dim3, with default size (1,1,1)
     */
    public dim3()
    {
        x = 1;
        y = 1;
        z = 1;
    }

    /**
     * Creates a new dim3, with the given size
     *
     * @param x The x size
     * @param y The y size
     * @param z The z size
     */
    public dim3(int x, int y, int z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "dim3["+
            "x="+x+","+
            "y="+y+","+
            "z="+z+"]";
    }
}
