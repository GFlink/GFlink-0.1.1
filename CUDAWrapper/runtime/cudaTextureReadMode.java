
package CUDAWrapper.runtime;

/**
 * Texture read modes
 *
 * @see textureReference
 */
public class cudaTextureReadMode
{
    /**
     * Element type read mode
     */
    public static final int cudaReadModeElementType = 0;

    /**
     * Normalized float read mode
     */
    public static final int cudaReadModeNormalizedFloat = 1;

    /**
     * Returns the String identifying the given cudaTextureReadMode
     *
     * @param m The cudaTextureReadMode
     * @return The String identifying the given cudaTextureReadMode
     */
    public static String stringFor(int m)
    {
        switch (m)
        {
            case cudaReadModeElementType: return "cudaReadModeElementType";
            case cudaReadModeNormalizedFloat: return "cudaReadModeNormalizedFloat";
        }
        return "INVALID cudaTextureReadMode: " + m;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaTextureReadMode()
    {
    }

};
