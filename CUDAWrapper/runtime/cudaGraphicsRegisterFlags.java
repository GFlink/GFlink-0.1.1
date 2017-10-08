package CUDAWrapper.runtime;

/**
 * CUDA graphics interop register flags
 */
public class cudaGraphicsRegisterFlags
{
    /**
     * Default
     */
    public static final int cudaGraphicsRegisterFlagsNone             = 0;

    /**
     * CUDA will not write to this resource
     */
    public static final int cudaGraphicsRegisterFlagsReadOnly         = 1;

    /**
     * CUDA will only write to and will not read from this resource
     */
    public static final int cudaGraphicsRegisterFlagsWriteDiscard     = 2;

    /**
     * CUDA will bind this resource to a surface reference
     */
    public static final int cudaGraphicsRegisterFlagsSurfaceLoadStore = 4;

    /**
     * CUDA will perform texture gather operations on this resource
     */
    public static final int cudaGraphicsRegisterFlagsTextureGather    = 8;

    /**
     * Returns the String identifying the given cudaGraphicsRegisterFlags
     *
     * @param n The cudaGraphicsRegisterFlags
     * @return The String identifying the given cudaGraphicsRegisterFlags
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaGraphicsRegisterFlagsNone: return "cudaGraphicsRegisterFlagsNone";
            case cudaGraphicsRegisterFlagsReadOnly: return "cudaGraphicsRegisterFlagsReadOnly";
            case cudaGraphicsRegisterFlagsWriteDiscard: return "cudaGraphicsRegisterFlagsWriteDiscard";
            case cudaGraphicsRegisterFlagsSurfaceLoadStore: return "cudaGraphicsRegisterFlagsSurfaceLoadStore";
            case cudaGraphicsRegisterFlagsTextureGather: return "cudaGraphicsRegisterFlagsTextureGather";
        }
        return "INVALID cudaGraphicsRegisterFlags: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaGraphicsRegisterFlags()
    {
    }

}
