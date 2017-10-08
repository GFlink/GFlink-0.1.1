package CUDAWrapper.runtime;

/**
 * CUDA GL Map Flags<br />
 */
public class cudaGLMapFlags
{
    /**
     * Default; Assume resource can be read/written
     */
    public static final int cudaGLMapFlagsNone    =   0;

    /**
     * CUDA kernels will not write to this resource
     */
    public static final int cudaGLMapFlagsReadOnly  =   1;

    /**
     * CUDA kernels will only write to and will not read from this resource
     */
    public static final int cudaGLMapFlagsWriteDiscard =   2;

    /**
     * Returns the String identifying the given cudaGLMapFlags
     *
     * @param n The cudaGLMapFlags
     * @return The String identifying the given cudaGLMapFlags
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaGLMapFlagsNone: return "cudaGLMapFlagsNone";
            case cudaGLMapFlagsReadOnly: return "cudaGLMapFlagsReadOnly";
            case cudaGLMapFlagsWriteDiscard: return "cudaGLMapFlagsWriteDiscard";
        }
        return "INVALID cudaGLMapFlags: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaGLMapFlags()
    {
    }

};

