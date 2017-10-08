
package CUDAWrapper.driver;

/**
 * GPU Direct v3 tokens. I don't have the slightest idea what this is.
 */
public class CUDA_POINTER_ATTRIBUTE_P2P_TOKENS
{
    public long p2pToken;

    public int vaSpaceToken;

    /**
     * Creates a new, uninitialized CUDA_POINTER_ATTRIBUTE_P2P_TOKENS
     */
    public CUDA_POINTER_ATTRIBUTE_P2P_TOKENS()
    {

    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "CUDA_POINTER_ATTRIBUTE_P2P_TOKENS["+createString(",")+"]";
    }

    /**
     * Creates and returns a formatted (aligned, multi-line) String
     * representation of this object
     *
     * @return A formatted String representation of this object
     */
    public String toFormattedString()
    {
        return "CUDA p2p tokensr:\n    "+createString("\n    ");
    }

    /**
     * Creates and returns a string representation of this object,
     * using the given separator for the fields
     *
     * @param f Separator
     * @return A String representation of this object
     */
    private String createString(String f)
    {
        StringBuilder sb = new StringBuilder();
        sb.append("p2pToken="+p2pToken+f);
        sb.append("vaSpaceToken="+vaSpaceToken+f);
        return sb.toString();
    }


}
