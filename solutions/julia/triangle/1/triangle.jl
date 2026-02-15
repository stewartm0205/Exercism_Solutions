function is_equilateral(sides)
    if sides[1] == 0
        return false
    end
    if sides[1]==sides[2] && sides[2]==sides[3]
        return true
    end
    return false
end

function is_isosceles(sides)
    if (sides[1]+sides[2]) < sides[3] ||
      (sides[1]+sides[3]) < sides[2] ||
      (sides[2]+sides[3]) < sides[1]
        return false
    end
    if sides[1]==sides[2] || sides[1]==sides[3] ||
        sides[2] == sides[3]
        return true
    end
    return false
end

function is_scalene(sides)
    if (sides[1]+sides[2])< sides[3] ||
        (sides[1]+sides[3])< sides[2] ||
        (sides[2]+sides[3]) < sides[1]
          return false
      end
      if sides[1]==sides[2] || sides[1]==sides[3] ||
        sides[2] == sides[3]
        return false
    end
    return true
end
