module Warmup exposing (..)

import List exposing (..)
import Basics exposing (..)
import Regex exposing (..)
import Date exposing (..)
import Date.Extra as Date exposing (..)


divmod x y =
    x // y


change : Int -> Result String ( Int, Int, Int, Int )
change amount =
    if amount < 0 then
        Err "amount cannot be negative"
    else
        Ok <|
            let
                a =
                    amount

                b =
                    a % 25

                c =
                    b % 10

                d =
                    c % 5
            in
                (,,,) (a // 25) (b // 10) (c // 5) (d)


stripQuotes : String -> String
stripQuotes input =
    replace All (regex "['\"]") (\_ -> "") <| input


powers : Int -> Int -> Result String (List Int)
powers base limit =
    if base < 0 then
        Err "negative base"
    else
        Ok <|
            List.map (\power -> base ^ power) (List.range 0 <| floor <| logBase (toFloat base) (toFloat limit))


sumOfCubesOfOdds : List Int -> Int
sumOfCubesOfOdds list =
    List.filter (\a -> a % 2 /= 0) list |> List.map (\a -> a ^ 3) |> List.foldr (+) 0


daysBetween : String -> String -> Result String Int
daysBetween firstString secondString =
    case Date.fromString firstString of
        Err msg ->
            Err "First input string is not a date."

        Ok firstDate ->
            case Date.fromString secondString of
                Err msg ->
                    Err "Second input string is not a date."

                Ok secondDate ->
                    Ok <| Date.diff Day firstDate secondDate
