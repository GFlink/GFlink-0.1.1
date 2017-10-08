
package CUDAWrapper.driver;

/**
 * Flags for cuStreamWriteValue32
 */
public class CUstreamWriteValue_flags
{
    /**
     * Default behavior 
     */
    public static final int CU_STREAM_WRITE_VALUE_DEFAULT           = 0x0;
    
    /**
     * Permits the write to be reordered with writes which were issued before
     * it, as a performance optimization. Normally, ::cuStreamWriteValue32 will
     * provide a memory fence before the write, which has similar semantics to
     * __threadfence_system() but is scoped to the stream rather than a CUDA
     * thread.
     */
    public static final int CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER = 0x1;

    /**
     * Returns the String identifying the given CUstreamWriteValue_flags
     *
     * @param n The CUstreamWriteValue_flags
     * @return The String identifying the given CUstreamWriteValue_flags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "CU_STREAM_WRITE_VALUE_DEFAULT";
        }
        String result = "";
        if ((n & CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER) != 0) result += "CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUstreamWriteValue_flags()
    {
        // Private constructor to prevent instantiation.
    }

}
