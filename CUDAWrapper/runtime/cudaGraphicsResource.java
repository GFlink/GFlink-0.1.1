package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.driver.CUgraphicsResource;

/**
 * Java port of a cudaGraphicsResource
 */
public class cudaGraphicsResource extends NativePointerObject
{
    /**
     * Creates a new, uninitialized cudaGraphicsResource
     */
    public cudaGraphicsResource()
    {
    }

    /**
     * Creates a cudaGraphicsResource for the given {@link CUgraphicsResource}. This
     * corresponds to casting a CUgraphicsResource to a cudaGraphicsResource.
     *
     * @param resource The other resource
     */
    public cudaGraphicsResource(CUgraphicsResource resource)
    {
        super(resource);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "cudaGraphicsResource["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }
}

