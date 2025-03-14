<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertStringNotContainsString($expected, $string);
        $this->assertStringNotContainsStringIgnoringCase($expected, $string);
        $this->assertStringEndsNotWith($expected, $string);
        $this->assertStringNotEqualsFile($expected, $string);
        $this->assertStringNotEqualsFileCanonicalizing($expected, $string);
        $this->assertStringNotEqualsFileIgnoringCase($expected, $string);
        $this->assertStringNotMatchesFormat($expected, $string);
        $this->assertStringNotMatchesFormatFile($expected, $string);
        $this->assertDoesNotMatchRegularExpression($expected, $string);
        $this->assertStringStartsNotWith($expected, $string);
        $this->assertJson($expected, $string);
        $this->assertStringContainsString($expected, $string);
        $this->assertStringContainsStringIgnoringCase($expected, $string);
        $this->assertStringEndsWith($expected, $string);
        $this->assertStringEqualsFile($expected, $string);
        $this->assertStringEqualsFileCanonicalizing($expected, $string);
        $this->assertStringEqualsFileIgnoringCase($expected, $string);
        $this->assertStringMatchesFormat($expected, $string);
        $this->assertStringMatchesFormatFile($expected, $string);
        $this->assertMatchesRegularExpression($expected, $string);
        $this->assertStringStartsWith($expected, $string);
    }
}

?>

-----
<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        expect($string)->stringNotToContainString($expected);
        expect($string)->stringNotToContainStringIgnoringCase($expected);
        expect($string)->stringNotToEndWith($expected);
        expect($string)->stringNotToEqualFile($expected);
        expect($string)->stringNotToEqualFileCanonicalizing($expected);
        expect($string)->stringNotToEqualFileIgnoringCase($expected);
        expect($string)->stringNotToMatchFormat($expected);
        expect($string)->stringNotToMatchFormatFile($expected);
        expect($string)->stringNotToMatchRegExp($expected);
        expect($string)->stringNotToStartWith($expected);
        expect($string)->stringToBeJson($expected);
        expect($string)->stringToContainString($expected);
        expect($string)->stringToContainStringIgnoringCase($expected);
        expect($string)->stringToEndWith($expected);
        expect($string)->stringToEqualFile($expected);
        expect($string)->stringToEqualFileCanonicalizing($expected);
        expect($string)->stringToEqualFileIgnoringCase($expected);
        expect($string)->stringToMatchFormat($expected);
        expect($string)->stringToMatchFormatFile($expected);
        expect($string)->stringToMatchRegExp($expected);
        expect($string)->stringToStartWith($expected);
    }
}

?>
