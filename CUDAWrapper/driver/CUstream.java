
package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.runtime.cudaStream_t;

/**
 * Java port of a CUstream.
 *
 * @see CUDAWrapperDriver#cuStreamCreate
 * @see CUDAWrapperDriver#cuStreamQuery
 * @see CUDAWrapperDriver#cuStreamSynchronize
 * @see CUDAWrapperDriver#cuStreamDestroy
 */
public class CUstream extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUstream
     */
    public CUstream()
    {
    }

    /**
     * Creates a CUstream for the given {@link cudaStream_t}. This
     * corresponds to casting a cudaStream_t to a CUstream.
     *
     * @param stream The other stream
     */
    public CUstream(cudaStream_t stream)
    {
        super(stream);
    }

    /**
     * Create a CUstream that is a constant with the given
     * value. This is used for emulating the stream
     * handling constants, {@link CUDAWrapperDriver#CU_STREAM_LEGACY}
     * and {@link CUDAWrapperDriver#CU_STREAM_PER_THREAD}
     *
     * @param value The pointer value
     */
    CUstream(long value)
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
        return "CUstream["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
