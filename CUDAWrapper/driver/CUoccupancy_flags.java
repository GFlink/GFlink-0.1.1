
package CUDAWrapper.driver;

/**
 * Occupancy calculator flag
 */
public class CUoccupancy_flags
{
    /** 
     * Default behavior 
     */
    public static final int CU_OCCUPANCY_DEFAULT                  = 0x0;
    
    /** 
     * Assume global caching is enabled and cannot be automatically turned off 
     */
    public static final int CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE = 0x1;
    
    /**
     * Returns the String identifying the given CUoccupancy_flags
     *
     * @param n The CUoccupancy_flags
     * @return The String identifying the given CUoccupancy_flags
     */
    public static String stringFor(int n)
    {
        String result = "CU_OCCUPANCY_DEFAULT ";
        if ((n & CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE) != 0) result += "CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUoccupancy_flags()
    {
    }
    
}
