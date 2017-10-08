

package CUDAWrapper.driver;

/**
 * CUDA Mem Attach Flags
 */
public class CUmemAttach_flags
{
    /**
     * Memory can be accessed by any stream on any device
     */
    public static final int CU_MEM_ATTACH_GLOBAL = 0x1;

    /**
     * Memory cannot be accessed by any stream on any device
     */
    public static final int CU_MEM_ATTACH_HOST   = 0x2;

    /**
     * Memory can only be accessed by a single stream on the
     * associated device
     */
    public static final int CU_MEM_ATTACH_SINGLE = 0x4;

    /**
     * Returns the String identifying the given CUmemAttach_flags
     *
     * @param n The CUmemAttach_flags
     * @return The String identifying the given CUmemAttach_flags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "INVALID CUmemAttach_flags: "+n;
        }
        String result = "";
        if ((n & CU_MEM_ATTACH_GLOBAL) != 0) result += "CU_MEM_ATTACH_GLOBAL ";
        if ((n & CU_MEM_ATTACH_HOST) != 0) result += "CU_MEM_ATTACH_HOST ";
        if ((n & CU_MEM_ATTACH_SINGLE) != 0) result += "CU_MEM_ATTACH_SINGLE ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUmemAttach_flags()
    {
    }

}
