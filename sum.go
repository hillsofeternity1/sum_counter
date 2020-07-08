package main

import "fmt"
import "runtime"

// COPYLEFT MIKHALIdCH 2018

func sum_chunk(first int, last int, channel chan int) {

  //fmt.Println("performing summ", first, last)
  result := 0
  for last >= first {
    num := last
    digit := 0
    for num > 0 {
      digit = num % 10
      result = result + digit
      num = num / 10
    }
    last--
  }
    //fmt.Println(result)
    channel <- result
}


func main() {
  // need to change it to getting from args
//var first, last int = 0, 1000000000
  var first, last int = 0, 1000000000000
  //fmt.Scanln(&first, "enter first value")
  //fmt.Scanln(&last, "enter last value")
  fmt.Println("Processing sequence from", first, "to", last)
  nprocs := runtime.NumCPU() * 3
  //nprocs = 1
  runtime.GOMAXPROCS(nprocs)
  if last <= nprocs {
    nprocs = 1
  }
  var shard, remainder int
    shard = last / nprocs
    fmt.Println("Shard size:", shard)
    remainder = last % nprocs
    fmt.Println("remainder:", remainder)
    channel := make(chan int)

  for i := first ; i < last ; i = i + shard {
        if i > last - shard {
             fmt.Println(i, last)
              go sum_chunk(i, last, channel)
         } else {
              fmt.Println(i, i + shard)
              go sum_chunk(i, i + shard, channel)
              i+=1
         }
    }

    result := 0
    for j := 0 ; j < nprocs ; j++ {
      result += <-channel
    }
    fmt.Printf("Result: %v\n", result)
}
