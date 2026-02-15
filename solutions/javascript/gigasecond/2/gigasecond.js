//
// This is only a SKELETON file for the 'Gigasecond' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const gigasecond = (curdate) => {

  var futdate = new Date (Date.UTC(curdate.getFullYear(),
                          curdate.getMonth(),
                          curdate.getDate(),
                          23, 0, 0, 0));
  //futdate.setHours(19);
  //futdate.setHours(24, 0, 0, 0);
  futdate.setSeconds(futdate.getTime() + 1000000000 * 1000)
  //console.log(futdate.getHours())
  //if (futdate.getHours() >= 19) futdate.setHours(20,59,59);
  return futdate;
};
