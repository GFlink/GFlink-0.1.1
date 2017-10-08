package CUDAWrapper.runtime;

/**
 * CUDA device P2P attributes
 */
public class cudaDeviceP2PAttr
{
    /**
     * A relative value indicating the performance of the link between two devices 
     */
    public static final int cudaDevP2PAttrPerformanceRank              = 1;

    /**
     * Peer access is enabled 
     */
    public static final int cudaDevP2PAttrAccessSupported              = 2;
    
    /**
     * Native atomic operation over the link supported 
     */
    public static final int cudaDevP2PAttrNativeAtomicSupported        = 3;  

    /**
     * Returns the String identifying the given cudaDeviceP2PAttr
     *
     * @param k The cudaDeviceP2PAttr
     * @return The String identifying the given cudaDeviceP2PAttr
     */
    public static String stringFor(int k)
    {
        switch (k)
        {
            case cudaDevP2PAttrPerformanceRank : return "cudaDevP2PAttrPerformanceRank";
            case cudaDevP2PAttrAccessSupported : return "cudaDevP2PAttrAccessSupported";
            case cudaDevP2PAttrNativeAtomicSupported : return "cudaDevP2PAttrNativeAtomicSupported";
        }
        return "INVALID cudaDeviceP2PAttr: "+k;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaDeviceP2PAttr()
    {

    }
};
