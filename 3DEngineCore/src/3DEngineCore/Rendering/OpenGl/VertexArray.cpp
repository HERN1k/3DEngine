#include "VertexArray.hpp"
#include "3DEngineCore/Log.hpp"
#include <glad/glad.h>

namespace Engine3D {
	
	VertexArray::VertexArray() {
		glGenVertexArrays(1, &m_id);
	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &m_id);
	}

	VertexArray& VertexArray::operator = (VertexArray&& vertex_array) noexcept {
		m_id = vertex_array.m_id;
		m_elements_count = vertex_array.m_id;
		vertex_array.m_id = 0;
		vertex_array.m_elements_count = 0;
		return *this;
	}

	VertexArray::VertexArray(VertexArray&& vertex_array) noexcept
		: m_id(vertex_array.m_id)
		, m_elements_count(vertex_array.m_elements_count) {
		
		vertex_array.m_id = 0;
		vertex_array.m_elements_count = 0;
	}

	void VertexArray::bind() const {
		glBindVertexArray(m_id);
	}

	void VertexArray::unbind() {
		glBindVertexArray(0); 
	}

	void VertexArray::add_buffer(const VertexBuffer& vertex_buffer) {
		bind();
		vertex_buffer.bind();

		for (const BufferElement& courent_element : vertex_buffer.get_layout().get_elements()) {
			glEnableVertexAttribArray(m_elements_count);
			glVertexAttribPointer(m_elements_count, 
				static_cast<GLint>(courent_element.components_count),
				courent_element.component_type,
				GL_FALSE,
				static_cast<GLsizei>(vertex_buffer.get_layout().get_stride()),
				reinterpret_cast<const void*>(courent_element.offset)
				);
			++m_elements_count;
		}
	}
}