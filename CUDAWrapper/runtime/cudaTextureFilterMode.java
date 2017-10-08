

package CUDAWrapper.runtime;

/**
 * Texture filter modes
 *
 * @see textureReference
 */
public class cudaTextureFilterMode
{
    /**
     * Point filter mode
     */
    public static final int cudaFilterModePoint = 0;

    /**
     * Linear filter mode
     */
    public static final int cudaFilterModeLinear = 1;

    /**
     * Returns the String identifying the given cudaTextureFilterMode
     *
     * @param m The cudaTextureFilterMode
     * @return The String identifying the given cudaTextureFilterMode
     */
    public static String stringFor(int m)
    {
        switch (m)
        {
            case cudaFilterModePoint: return "cudaFilterModePoint";
            case cudaFilterModeLinear: return "cudaFilterModeLinear";
        }
        return "INVALID cudaTextureFilterMode: " + m;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaTextureFilterMode()
    {
    }

}
