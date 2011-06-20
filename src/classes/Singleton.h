#ifndef SINGLETON_H
#define SINGLETON_H
#include <assert.h>

template<class C>
class Singleton {
	public:
		static C* Create() {
			// should be zero here, if we call second time, we will have a memory leak
			assert(!Singleton<C>::m_Instance);
			Singleton<C>::m_Instance = ::new C;
			return Singleton<C>::m_Instance;
		}
		static void Destroy() {
			// shouldn't be zero here, otherwise access violation
			assert(Singleton<C>::m_Instance);
			delete Singleton<C>::m_Instance;
			m_Instance = 0;
		}
		static C* GetInstance() {
			// shouldn't be zero here, otherwise possible access violation
			assert(Singleton<C>::m_Instance);
			return m_Instance;
		}
	protected:
		static C* m_Instance;
};

#define DefSingleton(C) template <> C* Singleton<C>::m_Instance = 0;

#endif // _SINGLETON_H_
