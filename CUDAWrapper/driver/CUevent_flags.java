

package CUDAWrapper.driver;

/**
 * Event creation flags.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.<br />
 * <br />
 * @see CUDAWrapperDriver#cuEventCreate(CUevent, int)
 */
public class CUevent_flags
{
    /**
     * Default event flag
     */
    public static final int CU_EVENT_DEFAULT       = 0x0;

    /**
     * Event uses blocking synchronization
     */
    public static final int CU_EVENT_BLOCKING_SYNC = 0x1;

    /**
     * Event will not record timing data
     */
    public static final int CU_EVENT_DISABLE_TIMING = 0x2;

    /**
     * Event is suitable for interprocess use. CU_EVENT_DISABLE_TIMING must be set
     */
    public static final int CU_EVENT_INTERPROCESS   = 0x4;

    /**
     * Returns the String identifying the given CUevent_flags
     *
     * @param n The CUevent_flags
     * @return The String identifying the given CUevent_flags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "CU_EVENT_DEFAULT";
        }
        String result = "";
        if ((n & CU_EVENT_BLOCKING_SYNC) != 0) result += "CU_EVENT_BLOCKING_SYNC ";
        if ((n & CU_EVENT_DISABLE_TIMING) != 0) result += "CU_EVENT_DISABLE_TIMING ";
        if ((n & CU_EVENT_INTERPROCESS) != 0) result += "CU_EVENT_INTERPROCESS ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUevent_flags()
    {
    }

}
