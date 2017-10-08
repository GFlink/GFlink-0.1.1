

package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.driver.CUstream;

/**
 * Java port of a cudaStream_t.
 *
 * @see CUDAWrapper#cudaStreamCreate
 * @see CUDAWrapper#cudaStreamQuery
 * @see CUDAWrapper#cudaStreamSynchronize
 * @see CUDAWrapper#cudaStreamDestroy
 */
public class cudaStream_t extends NativePointerObject
{
    /**
     * Creates a new, uninitialized cudaStream_t
     */
    public cudaStream_t()
    {
    }

    /**
     * Creates a cudaStream_t for the given {@link CUstream}. This
     * corresponds to casting a CUstream to a cudaStream_t.
     *
     * @param stream The other stream
     */
    public cudaStream_t(CUstream stream)
    {
        super(stream);
    }

    /**
     * Create a cudaStream_t that is a constant with the given
     * value. This is used for emulating the stream
     * handling constants, {@link CUDAWrapper#cudaStreamLegacy}
     * and {@link CUDAWrapper#cudaStreamPerThread()}
     *
     * @param value The pointer value
     */
    cudaStream_t(long value)
    {
        super(value);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "cudaStream_t["+
            "nativePointer="+getNativePointer()+"]";
    }

}
