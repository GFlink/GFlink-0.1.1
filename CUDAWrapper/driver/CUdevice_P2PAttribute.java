

package CUDAWrapper.driver;

/**
 * P2P Attributes.<br>
 * <br>
 * Most comments are taken from the CUDA headers and reference manual.<br>
 */
public class CUdevice_P2PAttribute
{
    /**
     * A relative value indicating the performance of the link between two devices 
     */
    public static final int CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK        = 0x01;

    /**
     * P2P Access is enable 
     */
    public static final int CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED        = 0x02;

    /**
     * Atomic operation over the link supported 
     */
    public static final int CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED = 0x03;

    /**
     * Returns the String identifying the given CUdevice_P2PAttribute
     *
     * @param n The CUdevice_P2PAttribute
     * @return The String identifying the given CUdevice_P2PAttribute
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK: return "CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK";
            case CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED: return "CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED";
            case CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED: return "CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED";
        }
        return "INVALID CUdevice_P2PAttribute: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUdevice_P2PAttribute()
    {
    }


}


