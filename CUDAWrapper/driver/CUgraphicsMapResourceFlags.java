
package CUDAWrapper.driver;

/**
 * Flags for mapping and unmapping interop resources
 */
public class CUgraphicsMapResourceFlags
{
    public static final int CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE          = 0x00;
    public static final int CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY     = 0x01;
    public static final int CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02;

    /**
     * Returns the String identifying the given CUgraphicsMapResourceFlags
     *
     * @param n The CUgraphicsMapResourceFlags
     * @return The String identifying the given CUgraphicsMapResourceFlags
     */
    public static String stringFor(int n)
    {
        if (n == 0)
        {
            return "CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE";
        }
        String result = "";
        if ((n & CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY    ) != 0) result += "CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY ";
        if ((n & CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD) != 0) result += "CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD ";
        return result;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUgraphicsMapResourceFlags()
    {
    }


}
