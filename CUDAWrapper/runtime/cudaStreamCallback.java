
package CUDAWrapper.runtime;

/**
 * Interface for emulating a CUDA stream callback.
 *
 * @see CUDAWrapper#cudaStreamAddCallback(cudaStream_t, cudaStreamCallback, Object, int)
 */
public interface cudaStreamCallback
{
    /**
     * The function that will be called
     *
     * @param stream The stream as passed to ::cudaStreamAddCallback, may be NULL.
     * @param status ::cudaSuccess or any persistent error on the stream.
     * @param userData User parameter provided at registration.
     */
    void call(cudaStream_t stream, int status, Object userData);
}
