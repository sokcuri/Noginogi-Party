#pragma once

template <class T>
class Singleton
{
public:
	static T *Instance() {
		if (!m_instance) {
			m_instance = new T();
		}
		return m_instance;
	}
private:
	static T *m_instance;
	virtual ~Singleton() { };
};

template<typename T>T *Singleton<T>::m_instance = 0;