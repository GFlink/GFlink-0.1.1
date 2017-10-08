package CUDAWrapper.runtime;

/**
 * Channel formats.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.
 *
 * @see cudaChannelFormatDesc
 */
public class cudaChannelFormatKind
{
    /**
     * Signed channel format
     */
    public static final int cudaChannelFormatKindSigned = 0;

    /**
     * Unsigned channel format
     */
    public static final int cudaChannelFormatKindUnsigned = 1;

    /**
     * Float channel format
     */
    public static final int cudaChannelFormatKindFloat = 2;

    /**
     *  No channel format
     */
    public static final int cudaChannelFormatKindNone = 3;

    /**
     * Returns the String identifying the given cudaChannelFormatKind
     *
     * @param f The cudaChannelFormatKind
     * @return The String identifying the given cudaChannelFormatKind
     */
    public static String stringFor(int f)
    {
        switch (f)
        {
            case cudaChannelFormatKindSigned: return "cudaChannelFormatKindSigned";
            case cudaChannelFormatKindUnsigned: return "cudaChannelFormatKindUnsigned";
            case cudaChannelFormatKindFloat: return "cudaChannelFormatKindFloat";
            case cudaChannelFormatKindNone: return "cudaChannelFormatKindNone";
        }
        return "INVALID cudaChannelFormatKind: "+f;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaChannelFormatKind()
    {
    }

}
