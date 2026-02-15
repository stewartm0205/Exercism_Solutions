/// <reference path="./global.d.ts" />
// @ts-check

/**
 * Implement the functions needed to solve the exercise here.
 * Do not forget to export them so they are available for the
 * tests. Here an example of the syntax as reminder:
 *
 * export function yourFunction(...) {
 *   ...
 * }
 */
export function cookingStatus (remainingTime) {
    if (remainingTime == undefined) return 'You forgot to set the timer.'
    if (remainingTime == 0) return 'Lasagna is done.'
    return 'Not done, please wait.'
}

export function preparationTime  (layers, averagePrepTime=2) {
    return layers.length * averagePrepTime;
}

export function quantities (layers) {
    var numNoodleLayers = 0;
    var numSauceLayers = 0;
    for (var layer of layers) {
        if (layer == 'noodles') numNoodleLayers++;
        if (layer == 'sauce') numSauceLayers++;
    }
    return { noodles: numNoodleLayers * 50, sauce : numSauceLayers * 0.2};
}

export function addSecretIngredient  (friendsList, myList) {
    myList.push(friendsList[friendsList.length-1]);
}

export function scaleRecipe (recipe, numPortions) {
    var scaledRecipe = {};
    for (var key in recipe){
        scaledRecipe[key] = (numPortions / 2) * recipe[key];
    }
    return scaledRecipe;
}