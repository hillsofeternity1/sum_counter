console.time('st')
const getNumSum = (num) => {
  let buf = num
  let res = 0;
  
  while (buf > 0) {
    res = res + buf % 10
    buf = Math.floor(buf / 10)
  }
  return res
}

const end =  1000000000
  let result = 0
  for(let i = 1; i <= end; i++){
    result += getNumSum(i)
  }

  
  console.log(result)
console.timeEnd('st')
