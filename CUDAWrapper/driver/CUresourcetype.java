
package CUDAWrapper.driver;

/**
 * Resource types
 */
public class CUresourcetype
{
    /**
     * Array resource
     */
    public static final int CU_RESOURCE_TYPE_ARRAY           = 0x00;

    /**
     * Mipmapped array resource
     */
    public static final int CU_RESOURCE_TYPE_MIPMAPPED_ARRAY = 0x01;

    /**
     * Linear resource
     */
    public static final int CU_RESOURCE_TYPE_LINEAR          = 0x02;

    /**
     * Pitch 2D resource
     */
    public static final int CU_RESOURCE_TYPE_PITCH2D         = 0x03;

    /**
     * Returns the String identifying the given CUresourcetype
     *
     * @param n The CUresourcetype
     * @return The String identifying the given CUresourcetype
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_RESOURCE_TYPE_ARRAY : return "CU_RESOURCE_TYPE_ARRAY";
            case CU_RESOURCE_TYPE_MIPMAPPED_ARRAY : return "CU_RESOURCE_TYPE_MIPMAPPED_ARRAY";
            case CU_RESOURCE_TYPE_LINEAR : return "CU_RESOURCE_TYPE_LINEAR";
            case CU_RESOURCE_TYPE_PITCH2D : return "CU_RESOURCE_TYPE_PITCH2D";
        }
        return "INVALID CUresourcetype: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUresourcetype()
    {
    }


}
