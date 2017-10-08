
package CUDAWrapper.runtime;


/**
 * CUDA resource types
 */
public class cudaResourceType
{
    /**
     * Array resource
     */
    public static final int cudaResourceTypeArray          = 0x00;

    /**
     * Mipmapped array resource
     */
    public static final int cudaResourceTypeMipmappedArray = 0x01;

    /**
     * Linear resource
     */
    public static final int cudaResourceTypeLinear         = 0x02;

    /**
     * Pitch 2D resource
     */
    public static final int cudaResourceTypePitch2D        = 0x03;

    /**
     * Returns the String identifying the given cudaResourceType
     *
     * @param k The cudaResourceType
     * @return The String identifying the given cudaResourceType
     */
    public static String stringFor(int k)
    {
        switch (k)
        {
            case cudaResourceTypeArray: return "cudaResourceTypeArray";
            case cudaResourceTypeMipmappedArray: return "cudaResourceTypeMipmappedArray";
            case cudaResourceTypeLinear: return "cudaResourceTypeLinear";
            case cudaResourceTypePitch2D: return "cudaResourceTypePitch2D";
        }
        return "INVALID cudaResourceType: "+k;
    }


    /**
     * Private constructor to prevent instantiation.
     */
    private cudaResourceType()
    {

    }
};
