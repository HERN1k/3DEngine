#pragma once

#include "VertexBuffer.hpp"

namespace Engine3D {

    class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        VertexArray(const VertexArray&) = delete;
        VertexArray& operator=(const VertexArray&) = delete;
        VertexArray& operator=(VertexArray&& vertex_bufer) noexcept;
        VertexArray(VertexArray&& vertex_bufer) noexcept;

        void add_buffer(const VertexBuffer& vertex_bufer);
        void bind() const;
        static void unbind();

    private:
        unsigned int m_id = 0;
        unsigned int m_elements_count = 0;
    };

}