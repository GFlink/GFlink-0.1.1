

package CUDAWrapper.driver;

/**
 * Flags for cuStreamWaitValue32
 */
public class CUstreamWaitValue_flags
{
    /**
     * Wait until (int32_t)(*addr - value) >= 0. Note this is a
     * cyclic comparison which ignores wraparound. (Default behavior.)
     */
    public static final int CU_STREAM_WAIT_VALUE_GEQ   = 0x0;

    /**
     * Wait until *addr == value.
     */
    public static final int CU_STREAM_WAIT_VALUE_EQ    = 0x1;
    
    /**
     * Wait until (*addr & value) != 0. 
     */
    public static final int CU_STREAM_WAIT_VALUE_AND   = 0x2;   
    
    /**
     * Follow the wait operation with a flush of outstanding remote writes. This
     * means that, if a remote write operation is guaranteed to have reached the
     * device before the wait can be satisfied, that write is guaranteed to be
     * visible to downstream device work. The device is permitted to reorder
     * remote writes internally. For example, this flag would be required if two
     * remote writes arrive in a defined order, the wait is satisfied by the
     * second write, and downstream work needs to observe the first write.
     */
    public static final int CU_STREAM_WAIT_VALUE_FLUSH = 1<<30;  

    /**
     * Returns the String identifying the given CUstreamWaitValue_flags
     *
     * @param n The CUstreamWaitValue_flags
     * @return The String identifying the given CUstreamWaitValue_flags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "CU_STREAM_WAIT_VALUE_GEQ";
        }
        String result = "";
        if ((n & CU_STREAM_WAIT_VALUE_EQ) != 0) result += "CU_STREAM_WAIT_VALUE_EQ ";
        if ((n & CU_STREAM_WAIT_VALUE_AND) != 0) result += "CU_STREAM_WAIT_VALUE_AND ";
        if ((n & CU_STREAM_WAIT_VALUE_FLUSH) != 0) result += "CU_STREAM_WAIT_VALUE_FLUSH ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUstreamWaitValue_flags()
    {
        // Private constructor to prevent instantiation.
    }

}
