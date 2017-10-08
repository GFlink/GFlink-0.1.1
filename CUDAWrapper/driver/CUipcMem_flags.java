

package CUDAWrapper.driver;

/**
 * Memory flags
 */
public class CUipcMem_flags
{
    /**
     * Automatically enable peer access between remote devices as needed
     */
    public static final int CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS = 0x1;

    /**
     * Returns the String identifying the given CUipcMem_flags
     *
     * @param n The CUipcMem_flags
     * @return The String identifying the given CUipcMem_flags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "INVALID CUipcMem_flags: "+n;
        }
        String result = "";
        if ((n & CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS) != 0) result += "CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUipcMem_flags()
    {
    }

}
