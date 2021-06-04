/**
* @file PermutationCipher.h
* @author Собачкин К.А.
* @version 1.0
* @brief Описание класса PermutationCipher
* @date 04.06.2021
* @copyright ИБСТ ПГУ
*/

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <locale>
using namespace std;
/// @brief Класс  расшифрования и шифрования шифра маршрутной табличной перестановки.
class PermutationCipher
{
private:
/// @brief Модуль, который хранит ключ для расшифрования или шифрования.
    int k;
    wstring getValidOpenText(const std::wstring & s);
    wstring getValidCipherText(const std::wstring & s);
    int getValidKey(const int k, const std::wstring & s);
public:
/// @brief Конструктор без параметров.
    PermutationCipher()=delete;
    /// @brief Конструктор для ключа
     /**  @param целочисленное значение  ключа
     *  @details значение, пришедшее на вход записывается в "private" в атрибут  "k"
     */
    PermutationCipher(int w);
    /**
     * @brief Метод  шифрования шифром табличной маршрутной перестановки
     * @param образец класса "PermutationCipher", в котором устанавливается ключ
     * @param "wstring" это строка зашифрования
     * @details
     * <p>Для начала вычисляется размер таблицы.
     * @code
     *  if (s.size()%w.k!=0) {
     *     h=s.size()/w.k+1;
     *  } else {
     *    h=s.size()/w.k;
     *  } // Вычисление размера таблицы. 
     * @endcode
     * Затем создаётся двумерный массив "wchar_t"
     * Количество строк вычисляется по формуле, а количество столбцов это ключ, который устанавливается 
     * в классе "PermutationCipher".</p> 
     * @code
     * wchar_t a[h][w.k];
     * @endcode
     * <p>После в созданный  массив записываются символы строки зашифрования.
     * Запись происходит по строкам.
     * @code
     * for (int i=0; i<h; i++) {
     *  for (int j=0; j<w.k; j++) {
     *      if (k<s.size()) {
     *          a[i][j]=s[k];
     *          k++;
     *      } else a[i][j]=' ';
     *  }
     *   }
     * @endcode
     * </p>
     * <p> После этого идёт сам процесс шифрования.
     * @code
     * for (int i=0; i<w.k; i++) {
     *  for (int j=0; j<h; j++) {
     *       code+=a[j][i];
     *   }
     * }
     * @endcode
     * </p>
     * @return "code" это зашифрованная строка типа "wstring"
     */
    wstring CoderPermutationCipher(PermutationCipher w, wstring& s);
    /**
     * @brief Метод  расшифрования шифром табличной маршрутной перестановки
     * @param образец класса "PermutationCipher", в котором устанавливается ключ
     * @details
     * <p>Сначала вычисляется размер таблицы.
     * @code
     *  if (s.size()%w.k!=0) {
     *   h=s.size()/w.k+1;
     *   } else {
     *   h=s.size()/w.k;
     *   }
     * @endcode
     * Затем создаётся двумерный массив "wchar_t"
     * Количество строк вычисляется по формуле, а количество столбцов это ключ, который устанавливается 
     * в классе "PermutationCipher".</p>
     * @code
     * wchar_t a[h][w.k];
     * @endcode
     * <p>После в созданный  массив записываются символы строки расшифрования
     * Запись происходит по строкам.
     * @code
     * for (int i=0; i<w.k; i++) {
     *  for (int j=0; j<h; j++) {
     *      a[j][i]=s[k];
     *     k++;
     *      }
     *  }
     * @endcode
     * @param "wstring" это строка  расшифрования
     * </p>
     * <p>После этого идёт сам процесс шифрования
     * @code
     * for (int i=0; i<h; i++) {
     *   for (int j=0; j<w.k; j++) {
     *      decode+=a[i][j];
     *      }
     *  }
     * @endcode
     * </p>
     * @return "decode" это зашифрованная строка типа "wstring"
     */
    wstring DecoderPermutationCipher(PermutationCipher w, wstring& s);
};

/// @class cipher_error - класс рассчитанный для возбуждения исключений

class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};