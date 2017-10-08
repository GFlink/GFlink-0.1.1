package CUDAWrapper.runtime;

/**
 * CUDA graphics interop map flags
 */
public class cudaGraphicsMapFlags
{
    /**
     * Default; Assume resource can be read/written
     */
    public static final int cudaGraphicsMapFlagsNone         = 0;

    /**
     * CUDA will not write to this resource
     */
    public static final int cudaGraphicsMapFlagsReadOnly     = 1;

    /**
     * CUDA will only write to and will not read from this resource
     */
    public static final int cudaGraphicsMapFlagsWriteDiscard = 2;


    /**
     * Returns the String identifying the given cudaGraphicsMapFlags
     *
     * @param n The cudaGraphicsMapFlags
     * @return The String identifying the given cudaGraphicsMapFlags
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaGraphicsMapFlagsNone: return "cudaGraphicsMapFlagsNone";
            case cudaGraphicsMapFlagsReadOnly: return "cudaGraphicsMapFlagsReadOnly";
            case cudaGraphicsMapFlagsWriteDiscard: return "cudaGraphicsMapFlagsWriteDiscard";
        }
        return "INVALID cudaGraphicsMapFlags: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaGraphicsMapFlags()
    {
    }

}
