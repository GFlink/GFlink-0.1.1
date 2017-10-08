

package CUDAWrapper.runtime;

/**
 * Texture address modes.
 *
 * @see textureReference
 */
public class cudaTextureAddressMode
{
    /**
     * Wrapping address mode
     */
    public static final int cudaAddressModeWrap = 0;

    /**
     * Clamping address mode
     */
    public static final int cudaAddressModeClamp = 1;

    /**
     * Returns the String identifying the given cudaTextureAddressMode
     *
     * @param m The cudaTextureAddressMode
     * @return The String identifying the given cudaTextureAddressMode
     */
    public static String stringFor(int m)
    {
        switch (m)
        {
            case cudaAddressModeWrap: return "cudaAddressModeWrap";
            case cudaAddressModeClamp: return "cudaAddressModeClamp";
        }
        return "INVALID cudaTextureAddressMode: " + m;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaTextureAddressMode()
    {
    }

}
