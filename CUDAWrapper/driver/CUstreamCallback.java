

package CUDAWrapper.driver;

/**
 * Interface for emulating a CUDA stream callback.
 *
 * @see CUDAWrapperDriver#cuStreamAddCallback(CUstream, CUstreamCallback, Object, int)
 */
public interface CUstreamCallback
{
    /**
     * The function that will be called
     *
     * @param hStream The stream the callback was added to, as passed to
     * {@link CUDAWrapperDriver#cuStreamAddCallback(CUstream, CUstreamCallback, Object, int)}.
     * May be NULL.
     * @param status CUDA_SUCCESS or any persistent error on the stream.
     * @param userData User parameter provided at registration.
     */
    void call(CUstream hStream, int status, Object userData);
}

