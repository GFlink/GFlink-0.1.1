
package CUDAWrapper.driver;

/**
 * Shared memory configurations
 */
public class CUsharedconfig
{
    /**
     * Set default shared memory bank size
     */
    public static final int CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE    = 0x00;

    /**
     *  Set shared memory bank width to four bytes
     */
    public static final int CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE  = 0x01;

    /**
     * Set shared memory bank width to eight bytes
     */
    public static final int CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE = 0x02;

    /**
     * Returns the String identifying the given CUsharedconfig
     *
     * @param n The CUsharedconfig
     * @return The String identifying the given CUsharedconfig
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE: return "CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE";
            case CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE: return "CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE";
            case CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE: return "CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE";
        }
        return "INVALID CUsharedconfig: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUsharedconfig()
    {
    }

}



