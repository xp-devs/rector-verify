<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertFileIsNotReadable($file);
        $this->assertFileIsNotWritable($file);
        $this->assertFileDoesNotExist($file);
        $this->assertFileEquals($file);
        $this->assertFileEqualsCanonicalizing($file);
        $this->assertFileEqualsIgnoringCase($file);
        $this->assertFileIsReadable($file);
        $this->assertFileIsWritable($file);
        $this->assertFileExists($file);
        $this->assertFileNotEquals($file);
        $this->assertFileNotEqualsCanonicalizing($file);
        $this->assertFileNotEqualsIgnoringCase($file);
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
        expect($file)->fileNotToBeReadable();
        expect($file)->fileNotToBeWritable();
        expect($file)->fileNotToExist();
        expect($file)->fileToBeEqual();
        expect($file)->fileToBeEqualCanonicalizing();
        expect($file)->fileToBeEqualIgnoringCase();
        expect($file)->fileToBeReadable();
        expect($file)->fileToBeWritable();
        expect($file)->fileToExist();
        expect($file)->fileToNotEqual();
        expect($file)->fileToNotEqualCanonicalizing();
        expect($file)->fileToNotEqualIgnoringCase();
    }
}

?>
