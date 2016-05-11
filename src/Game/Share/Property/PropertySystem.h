#pragma once

#define WritableP fuu::WritableProperty
#define ReadOnlyP fuu::ReadOnlyProperty

namespace fuu
{
	// ゲッター
	template<typename T>
	struct PropertyGetter
	{
		static const T& Get(const T& value)
		{
			return value;
		}
	};

	// セッター
	template<typename T>
	struct PropretySetter
	{
		static void Set(T& value, const T& var)
		{
			value = T(var);
		}
	};

	// プロパティ
	template<typename T>
	class Property
	{
	protected:
		T& _value;

	public:
		Property(T& value) : _value(value) {}
		Property(const Property& ref) :
			_value(ref._value) {}

		virtual ~Property() {}

		Property<T>& operator = (const Property<T>& ref)
		{
			this->_value = T(ref._value);
			return *this;
		}

	};

	//　読み書きできるプロパティ
	template<typename T, class Getter = PropertyGetter<T>, class Setter = PropretySetter<T>>
	class WritableProperty : public Property<T>, private Getter, private Setter
	{
	public:
		WritableProperty(T& value) :
			Property<T>(value) {}
		WritableProperty(const WritableProperty& ref) :
			Property<T>(ref) {}
		virtual ~WritableProperty() {}

	public:
		operator const T& () const
		{
			return this->Get(this->_value);
		}
		const T& operator -> () const
		{
			return this->Get(this->_value);
		}

		WritableProperty<T, Getter, Setter>& operator = (const T& var)
		{
			this->Set(this->_value, var);
			return *this;
		}
	};

	// 読み取り専用プロパティ
	template<typename T, class Getter = PropertyGetter<T>>
	class ReadOnlyProperty : public Property<T>, private Getter
	{
	public:
		ReadOnlyProperty(T& value) :
			Property<T>(value) {}
		ReadOnlyProperty(const ReadOnlyProperty& ref) :
			Property<T>(ref) {}
		virtual ~ReadOnlyProperty() {}

	public:
		operator const T& () const
		{
			return this->Get(this->_value);
		}

		const T& operator -> ()const
		{
			return this->Get(this->_value);
		}

	};

}