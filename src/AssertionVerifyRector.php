<?php
declare(strict_types=1);

namespace XpDevs\RectorVerify;

use PhpParser\Node;
use PHPUnit\Framework\TestCase;
use Rector\Rector\AbstractRector;

class AssertionVerifyRector extends AbstractRector
{
    public function getNodeTypes(): array
    {
        return [Node\Stmt\Expression::class];
    }

    /**
     * @param Node\Stmt\Expression $node
     * @return Node\Stmt\Expression
     */
    public function refactor(Node $node)
    {
        /** @var \ReflectionClass $reflClass */
        $reflClass = $node->getAttribute('scope')->getClassReflection();

        if (!$reflClass->isSubclassOf(TestCase::class)) {
            return $node;
        }

        $expr = $node->expr;
        $isMethodCall = $expr instanceof Node\Expr\StaticCall || $expr instanceof Node\Expr\MethodCall;

        if (!$isMethodCall) {
            return $node;
        }

        if ($expr->name->name === 'assertEquals') {
            $expect = new Node\Expr\FuncCall(new Node\Name('expect'), [$expr->args[1]]);
            $node->expr = new Node\Expr\MethodCall($expect, new Node\Identifier('toEqual'), [$expr->args[0]]);
        }

        return $node;
    }
}
