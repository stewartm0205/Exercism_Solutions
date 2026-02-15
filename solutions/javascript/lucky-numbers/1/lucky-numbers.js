// @ts-check

/**
 * Calculates the sum of the two input arrays.
 *
 * @param {number[]} array1
 * @param {number[]} array2
 * @returns {number} sum of the two arrays
 */
export function twoSum(array1, array2) {
  var num1=0;
  for (var ni = 0; ni<array1.length; ni++) {
    num1 = num1 * 10 + array1[ni];
  }
  var num2=0;
  for (var ni = 0; ni<array2.length; ni++) {
    num2 = num2 * 10 + array2[ni];
  }
  return num1 + num2;
}

/**
 * Checks whether a number is a palindrome.
 *
 * @param {number} value
 * @returns {boolean}  whether the number is a palindrome or not
 */
export function luckyNumber(value) {
  var valuestr = value.toString()
  var valuestrrev = valuestr.split('').reverse().join('');
  if (valuestr == valuestrrev) return true;
  return false;
}

/**
 * Determines the error message that should be shown to the user
 * for the given input value.
 *
 * @param {string|null|undefined} input
 * @returns {string} error message
 */
export function errorMessage(input) {
  if (!input) return 'Required field';
  if (!/^ *[0-9.e]* *$/.test(input)) return 'Must be a number besides 0';
  if (parseInt(input.trim()) == 0) return 'Must be a number besides 0';
  return '';
}
