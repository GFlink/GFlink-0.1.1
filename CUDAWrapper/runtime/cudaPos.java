
package CUDAWrapper.runtime;

/**
 * Java port of a cudaPos.
 *
 * @see cudaMemcpy3DParms
 */
public class cudaPos
{
    /**
     * The x component
     */
    public long x;

    /**
     * The y component
     */
    public long y;

    /**
     * The z component
     */
    public long z;

    /**
     * Creates a new cudaPos at (0,0,0)
     */
    public cudaPos()
    {
    }

    /**
     * Creates a new cudaPos with the given position
     *
     * @param x The x component
     * @param y The y component
     * @param z The z component
     */
    public cudaPos(long x, long y, long z)
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
        return "cudaPos["+
            "x="+x+","+
            "y="+y+","+
            "z="+z+"]";
    }
}