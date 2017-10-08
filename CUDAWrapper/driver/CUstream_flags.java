
package CUDAWrapper.driver;

/**
 * Stream creation flags.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.<br />
 * <br />
 * @see CUDAWrapperDriver#cuStreamCreate(CUstream, int)
 */
public class CUstream_flags
{
    /**
     * Default stream flag
     */
    public static final int CU_STREAM_DEFAULT       = 0x0;

    /**
     * Stream does not synchronize with stream 0 (the NULL stream)
     */
    public static final int CU_STREAM_NON_BLOCKING = 0x1;

    /**
     * Returns the String identifying the given CUstream_flags
     *
     * @param n The CUstream_flags
     * @return The String identifying the given CUstream_flags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "CU_STREAM_DEFAULT";
        }
        String result = "";
        if ((n & CU_STREAM_NON_BLOCKING) != 0) result += "CU_STREAM_NON_BLOCKING ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUstream_flags()
    {
    }

}
