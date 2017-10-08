
package CUDAWrapper.driver;

/**
 * Compute Modes. <br />
 * <br />
 * Most comments are taken from the CUDA reference manual.<br />
 * <br />
 * @see CUdevice_attribute#CU_DEVICE_ATTRIBUTE_COMPUTE_MODE
 */
public class CUcomputemode
{

    /**
     * Default compute mode (Multiple contexts allowed per device)
     */
    public static final int CU_COMPUTEMODE_DEFAULT    = 0;

    /**
     * Compute-exclusive-thread mode (Only one context used by a
     * single thread can be present on this device at a time)
     * 
     * @deprecated Removed in CUDA 8.0.27
     */
    public static final int CU_COMPUTEMODE_EXCLUSIVE  = 1;

    /**
     * Compute-prohibited mode (No contexts can be created on
     * this device at this time)
     */
    public static final int CU_COMPUTEMODE_PROHIBITED = 2;

    /**
     * Compute-exclusive-process mode (Only one context used by a
     * single process can be present on this device at a time)
     */
    public static final int CU_COMPUTEMODE_EXCLUSIVE_PROCESS = 3;


    /**
     * Returns the String identifying the given CUcomputemode
     *
     * @param n The CUcomputemode
     * @return The String identifying the given CUcomputemode
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_COMPUTEMODE_DEFAULT: return "CU_COMPUTEMODE_DEFAULT";
            case CU_COMPUTEMODE_EXCLUSIVE: return "CU_COMPUTEMODE_EXCLUSIVE";
            case CU_COMPUTEMODE_PROHIBITED: return "CU_COMPUTEMODE_PROHIBITED";
            case CU_COMPUTEMODE_EXCLUSIVE_PROCESS: return "CU_COMPUTEMODE_EXCLUSIVE_PROCESS";
        }
        return "INVALID CUcomputemode: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUcomputemode()
    {
    }


}


